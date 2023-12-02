using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employees
{
    internal class Employee
    {
        public string Name { get; set; }
        public int Id { get; set; }
        public bool IsEmployed { get; set; }
        public Employee(string name, int id, bool isEmployed)
        {
            Name = name;
            Id = id;
            IsEmployed = isEmployed;
        }
    }
}
