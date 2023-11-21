using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using InterfaceOfFile;
using Entity;

namespace InterfaceRealization
{
    public class FileService : IFileService<Product>
    {
        public IEnumerable<Product> ReadFile(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new FileNotFoundException();
            }
            using (FileStream fileStream = File.OpenRead(fileName))
            {
                using (BinaryReader reader = new(fileStream))
                {
                    while (fileStream.Position < fileStream.Length)
                    {
                        string name;
                        int price;
                        bool sold;
                        try
                        {
                            name = reader.ReadString();
                            price = reader.ReadInt32();
                            sold = reader.ReadBoolean();
                        }
                        catch (Exception exep)
                        {
                            Console.WriteLine(exep.Message);
                            yield break;
                        }
                        yield return new Product(name, price, sold);
                    }
                }
            }
        }
        public void SaveData(IEnumerable<Product> data, string fileName)
        {
            using (FileStream fileStream = File.Open(fileName, FileMode.OpenOrCreate))
            {
                using (BinaryWriter writer = new(fileStream))
                {
                    foreach (Product product in data)
                    {
                        (string name, int price, bool sold) = product;
                        try
                        {
                            writer.Write(name);
                            writer.Write(price);
                            writer.Write(sold);
                        }
                        catch (Exception exep)
                        {
                            Console.WriteLine(exep.Message);
                            break;
                        }
                    }
                }
            }
        }
    }
}
