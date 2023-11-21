using InterfaceRealization;
using Entity;
using Comparer;
using InterfaceOfFile;
using InterfaceRealization;

namespace lab4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Product> products = new();
            products.Add(new Product("Хлеб", 20, false));
            products.Add(new Product("Батон", 50, false));
            products.Add(new Product("Квас", 70, true));
            products.Add(new Product("Сыр", 90, false));
            products.Add(new Product("Помидор", 100, false));
            products.Add(new Product("Чай", 10, true));
            Random rand = new Random();
            string folderName = @"C:\zxc\lab4\Files";
            string[] extensions = { ".txt", ".rft", ".dat", ".inf" };
            for (int i = 0; i < 10; i++)
            {
                string fileName = Path.Combine(folderName, string.Concat(Path.GetRandomFileName(), extensions[rand.Next(0, extensions.Length)]));
                File.Create(fileName).Close();
            }
            if (Directory.Exists(folderName))
            {
                string[] files = Directory.GetFiles(folderName);
                foreach (string file in files)
                {
                    string fileName = Path.GetFileName(file);
                    string fileExtension = Path.GetExtension(file);
                    Console.WriteLine($"Файл: {fileName} имеет расширение {fileExtension}");
                }
            }
            Console.WriteLine();
            string[] filess = Directory.GetFiles(folderName);
            string filee = filess[rand.Next(0, filess.Length)];
            FileService fileService = new FileService();
            fileService.SaveData(products, filee);
            string newFilePath = @"C:\zxc\lab4\Files\newFileName.txt";
            File.Move(filee, newFilePath);
            List<Product> products2 = new();
            foreach (var product in fileService.ReadFile(newFilePath))
            {
                products2.Add(product);
            }
            File.Delete(newFilePath);
            Console.WriteLine("Список продуктов: ");
            foreach (Product product in products2)
            {
                Console.WriteLine($"-- Имя: {product.Name}, цена: {product.Price}, продано: {product.Sold}");
            }
            Console.WriteLine();
            List<Product> sort_name = products2.OrderBy(product => product, new MyCustomComparer()).ToList();
            Console.WriteLine("Список продуктов(после сортировки по имени): ");
            foreach (Product product in sort_name)
            {
                Console.WriteLine($"-- Имя: {product.Name}, цена: {product.Price}, продано: {product.Sold}");
            }
            Console.WriteLine();
            List<Product> sort_price = products2.OrderBy(product => product.Price).ToList();
            Console.WriteLine("Список продуктов(после сортировки по цене): ");
            foreach (Product product in sort_price)
            {
                Console.WriteLine($"-- Имя: {product.Name}, цена: {product.Price}, продано: {product.Sold}");
            }
        }
    }
}