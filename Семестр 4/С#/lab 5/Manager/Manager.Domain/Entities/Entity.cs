using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Domain.Entities
{
    public abstract class Entity
    {
        public Entity() { }
        public Entity(string name) 
        {
            Name = name;
        }
        public int Id { get; set; }
        public string Name { get; set; }
    }
}
