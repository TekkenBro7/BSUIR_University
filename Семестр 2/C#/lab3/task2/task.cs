namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            func f = new();

            f.n = double.Parse(Console.ReadLine());
            f.m = double.Parse(Console.ReadLine());
            f.k = double.Parse(Console.ReadLine());

            f.Function(f.n, f.m, f.k);
        }
    }
}
