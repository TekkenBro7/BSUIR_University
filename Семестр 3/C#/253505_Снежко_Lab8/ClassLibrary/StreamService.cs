using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace ClassLibrary
{
    public class StreamService<T> where T : class
    {
        public static Semaphore semaphore = new(1, 1);
        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
        {
            progress.Report($"Начинается запись в поток {Thread.CurrentThread.ManagedThreadId}");          
            double totalCount = data.Count();
            double processedCount = 0;
            semaphore.WaitOne();
            try
            {
                await JsonSerializer.SerializeAsync(stream, data);
                await Task.Delay(3000);
            }
            finally
            {
                semaphore.Release();
            }
            foreach (var item in data)
            {
                processedCount += 1;
                double percentage = (processedCount / totalCount) * 100;
                progress.Report($"Поток {Thread.CurrentThread.ManagedThreadId}: {percentage:F2}%");
                await Task.Delay(2);
            }
            progress.Report($"Конец записи в поток {Thread.CurrentThread.ManagedThreadId}");
        }
        public async Task CopyFromStreamAsync(Stream stream, string filename, IProgress<string> progress)
        {
            progress.Report($"Начало записи в файл {Thread.CurrentThread.ManagedThreadId}");
            await Task.Delay(3000);
            await using var file = File.Open(filename, FileMode.Create);
            stream.Position = 0;
            semaphore.WaitOne();
            try
            {
                await stream.CopyToAsync(file);
            }
            finally
            {
                semaphore.Release();
            }
            progress.Report($"Конец записи в файл {Thread.CurrentThread.ManagedThreadId}");
        }
        public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
        {
            await using var file = File.Open(fileName, FileMode.Open);
            List<T> list = await JsonSerializer.DeserializeAsync<List<T>>(file) ?? new List<T>();
            return list.Count(filter);
        }
    }
}
