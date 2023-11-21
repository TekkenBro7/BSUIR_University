using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace lab5.Domain
{
    public class Library : IEquatable<Library>
    {
        public List<BookDepository> Depository { get; set; }
        public string Name { get; set; }
        public Library() { Depository = new(); }
        public Library(string name)
        {
            Name = name;
            Depository = new List<BookDepository>();
        }
        public Library(string name, List<BookDepository> list)
        {
            Name = name;
            Depository = list;
        }
        public void AddBookDepository(BookDepository depository)
        {
            Depository.Add(depository);
        }
        public bool Equals(Library? other)
        {
            return Name == other.Name && Depository == other.Depository;
        }
    }
}
