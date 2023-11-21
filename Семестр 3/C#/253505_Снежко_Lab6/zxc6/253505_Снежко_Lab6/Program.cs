using Employees;
using System.Reflection;

namespace _253505_Снежко_Lab6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employees = new();
            employees.Add(new Employee("Maxim", 1, true));
            employees.Add(new Employee("Misha", 2, false));
            employees.Add(new Employee("Andrey", 3, true));
            employees.Add(new Employee("Vanya", 4, false));
            employees.Add(new Employee("Sanya", 5, true));
            employees.Add(new Employee("Vlad", 6, false));
            string fileName = "file.json";
            Assembly asm = Assembly.LoadFrom("C:\\zxc6\\FileService\\bin\\Debug\\net7.0\\FileServiceDLL.dll");
            Type? type = asm.GetType("Services.FileService`1");
            var genericType = type.MakeGenericType(new[] { typeof(Employee) });
            object? instance = Activator.CreateInstance(genericType);
            genericType.GetMethod("SaveData", BindingFlags.Instance | BindingFlags.Public)
                            .Invoke(instance, new object[] { employees, fileName });
            var list = (IEnumerable<Employee>)genericType.GetMethod("ReadFile", BindingFlags.Instance | BindingFlags.Public)
                            .Invoke(instance, new object[] { fileName });
            foreach (var employee in list)
            {
                Console.WriteLine($"Имя работника: {employee.Name}, id: {employee.Id}, занят: {employee.IsEmployed}");
            }
        }
    }
}