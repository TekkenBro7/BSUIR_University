using Collections;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Journal_Class
{
    internal class Journal
    {
        private MyCustomCollection<string> logs;
        public Journal()
        {
            logs = new MyCustomCollection<string>();
        }
        public void Log(string log)
        {
            logs.Add(log);
        }
        public string GetLogs()
        {
            string res = "События журнала:\n";
            foreach (var item in logs)
            {
                res += item + "\n";
            }
            return res;
        }
    }
}
