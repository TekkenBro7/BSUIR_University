using System.Diagnostics;

namespace Integral
{
    public class IntegralCalculation
    {
        public static Semaphore semaphore = new(5, 5);
        public delegate void NotifyDelegate(double x);
        public event NotifyDelegate? AchievementProgressEvent;
        public event NotifyDelegate? ElapsedTimeEvent;
        public event NotifyDelegate? SinResultEvent;
        private const int DownLimit = 0;
        private const int UpLimit = 1;
        private const double Step = 0.00000001;
        public void Integrate()
        {
            semaphore.WaitOne();
            double result = 0;
            double achievementProgress = 0;
            Stopwatch sw = Stopwatch.StartNew();
            sw.Start();
            for (double i = DownLimit; i < UpLimit; i += Step)
            {
                result += Step * SinValue(i);
                if (achievementProgress + 0.1 < (i - DownLimit) / (UpLimit - DownLimit) * 100)
                {
                    achievementProgress += 1;
                    AchievementProgressEvent?.Invoke(achievementProgress);
                }
            //    for (int j = 0; j < 1000; j++) _ = 0 * 0;
            }
            sw.Stop();     
            SinResultEvent?.Invoke(result);
            ElapsedTimeEvent?.Invoke(sw.ElapsedMilliseconds);
            semaphore.Release();
        }
        private double SinValue(double num) => Math.Sin(num);
    }
}