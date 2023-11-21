using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using lab5.Domain;
using System.Text.Json;
using System.Xml.Serialization;
using System.Xml.Linq;

namespace SerializerLib
{
    public class Serializer : ISerializer
    {
        public IEnumerable<Library> DeSerializeByLINQ(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new FileNotFoundException("Файла не существует");
            }
            XDocument xDocument = XDocument.Load(fileName);
            return (from library in xDocument.Descendants("library")
                    select new Library(
                        (string)library.Element("name"),
                        (from bookdepository in library.Descendants("bookdepository")
                         select new BookDepository(
                            (from book in bookdepository.Descendants("book")
                             select new Book(
                                 (string)book.Element("name"),
                                 (string)book.Element("author"),
                                 (int)book.Element("year")
                             )).ToList()
                         )).ToList()
                    ));
        }
        public IEnumerable<Library> DeSerializeJSON(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new FileNotFoundException("Файла не существует");
            }
            string jsonContent = File.ReadAllText(fileName);
            var LibraryList = JsonSerializer.Deserialize<List<Library>>(jsonContent);
            foreach (var item in LibraryList)
            {
                yield return item;
            }
        }
        public IEnumerable<Library> DeSerializeXML(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new FileNotFoundException("Файла не существует");
            }
            XmlSerializer serializer = new(typeof(List<Library>));
            using (var stream = File.OpenRead(fileName))
            {
                var LibraryList = serializer.Deserialize(stream) as List<Library>;
                foreach (var item in LibraryList)
                {
                    yield return item;
                }
            }
        }
        public void SerializeByLINQ(IEnumerable<Library> list, string fileName)
        {
            XDocument xDocument = new XDocument();
            XElement xLibraries = new XElement("libraries");
            foreach (Library library in list)
            {
                XElement xLibrary = new XElement("library");
                xLibrary.Add(new XElement("name", library.Name));
                XElement xBookDepositories = new XElement("bookdepositories");
                foreach (BookDepository bookDepository in library.Depository)
                {
                    XElement xBookDepository = new XElement("bookdepository");
                    foreach (Book item in bookDepository.Books)
                    {
                        XElement xBook = new XElement("book");
                        xBook.Add(new XElement("name", item.Name));
                        xBook.Add(new XElement("author", item.Author));
                        xBook.Add(new XElement("year", item.Year));
                        xBookDepository.Add(xBook);
                    }
                    xBookDepositories.Add(xBookDepository);
                }
                xLibrary.Add(xBookDepositories);
                xLibraries.Add(xLibrary);
            }
            xDocument.Add(xLibraries);
            xDocument.Save(fileName);
        }
        public void SerializeJSON(IEnumerable<Library> list, string fileName)
        {
            using (var stream = File.CreateText(fileName))
            {
                var jsonString = JsonSerializer.Serialize(list);
                stream.Write(jsonString);
            }
        }
        public void SerializeXML(IEnumerable<Library> list, string fileName)
        {
            XmlSerializer serializer = new(typeof(List<Library>));
            using (var stream = File.CreateText(fileName))
            {
                serializer.Serialize(stream, list);
            }
        }
    }
}
