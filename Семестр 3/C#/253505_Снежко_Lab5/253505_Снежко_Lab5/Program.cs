using lab5.Domain;
using SerializerLib;

namespace _253505_Снежко_Lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Library> libraries = new();
            Library library1 = new("Русское");
            Library library2 = new("Беларусское");
            library1.AddBookDepository(new BookDepository(new List<Book>
            {
                new Book("Война и мир", "Толстой", 1867),
                new Book("Преступление и наказание", "Достоевский", 1866),
                new Book("Мастер и Маргарита", "Булгаков", 1967),
            }));
            library2.AddBookDepository(new BookDepository(new List<Book>
            {
                new Book("Людзи на балоце", "Мележ", 1962),
                new Book("Знак бяды", "Быкаў", 1982),
                new Book("Сэрца на далони", "Шамякин", 1964),
            }));
            Serializer serializer = new();
            libraries.Add(library1);
            libraries.Add(library2);
            List<Library> librariesJson = new();
            List<Library> librariesXml = new();
            List<Library> librariesLinq = new();
            serializer.SerializeJSON(libraries, "file.json");
            var a = serializer.DeSerializeJSON("file.json");
            foreach (Library library in serializer.DeSerializeJSON("file.json"))
            {
                Console.WriteLine(library.Name);
                foreach (var depository in library.Depository)
                {
                    foreach (var book in depository.Books)
                    {
                        Console.WriteLine($"Название книги: {book.Name}, автор: {book.Author}, год создания: {book.Year}");
                    }
                    Console.WriteLine();
                }
                librariesJson.Add(new Library(library.Name, library.Depository));
            }
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();
            serializer.SerializeXML(libraries, "file.xml");
            foreach (Library library in serializer.DeSerializeXML("file.xml"))
            {
                Console.WriteLine(library.Name);
                foreach (var depository in library.Depository)
                {
                    foreach (var book in depository.Books)
                    {
                        Console.WriteLine($"Название книги: {book.Name}, автор: {book.Author}, год создания: {book.Year}");
                    }
                    Console.WriteLine();
                }
                librariesXml.Add(new Library(library.Name, library.Depository));
            }
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();
            serializer.SerializeByLINQ(libraries, "file.linq");
            foreach (Library library in serializer.DeSerializeByLINQ("file.linq"))
            {
                Console.WriteLine(library.Name);
                foreach (var depository in library.Depository)
                {
                    foreach (var book in depository.Books)
                    {
                        Console.WriteLine($"Название книги: {book.Name}, автор: {book.Author}, год создания: {book.Year}");
                    }
                    Console.WriteLine();
                }
                librariesLinq.Add(new Library(library.Name, library.Depository));
            }
            if (libraries.SequenceEqual(a)) Console.WriteLine("Идентично после JSON");
            if (libraries.SequenceEqual(librariesXml)) Console.WriteLine("Идентично после XML");
            if (libraries.SequenceEqual(librariesLinq)) Console.WriteLine("Идентично после LINQ");
        }
    }
}