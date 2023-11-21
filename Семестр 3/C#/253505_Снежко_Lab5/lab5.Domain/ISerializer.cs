using lab5.Domain;
namespace lab5.Domain
{
    public interface ISerializer
    {
        IEnumerable<Library> DeSerializeByLINQ(string fileName);    
        IEnumerable<Library> DeSerializeXML(string fileName);
        IEnumerable<Library> DeSerializeJSON(string fileName);
        void SerializeByLINQ(IEnumerable<Library> list, string fileName);
        void SerializeXML(IEnumerable<Library> list, string fileName);
        void SerializeJSON(IEnumerable<Library> list, string fileName);
    }
}