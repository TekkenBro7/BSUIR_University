using System.IO;
using System.Threading.Tasks;
using ClassLibrary;
using LoremNET;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _253505_Снежко_Lab8
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            List<Product> products = new();
            IProgress<string> progress = new Progress<string>(message =>
            {
                Console.WriteLine(message);
            });
            Random rand = new();
            for (int i = 0; i < 1000; i++)
            {
                Product product = new();
                product.Id = i+1;
                product.Name = LoremNET.Lorem.Words(2);
                product.EndSrotageLife = rand.Next(0, 2) == 1;     
                products.Add(product);
            }
            StreamService<Product> streamService = new();
            MemoryStream stream = new();
            var writerTask = streamService.WriteToStreamAsync(stream, products, progress);
            await Task.Delay(100);
            var copierTask = streamService.CopyFromStreamAsync(stream, "data.json", progress);
            await Task.WhenAll(writerTask, copierTask);
            int count = await streamService.GetStatisticsAsync("data.json", (Product car) => car.EndSrotageLife == true);
            Console.WriteLine($"Количетсво товаров, у которых закончился срок хранения: {count}");
        }
    }
}