using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab7
{
    internal class Triangle
    {
        private double[] Sides;
        public Triangle(double firstStorona, double secondStorona, double thirdStorona)
        {
            if (firstStorona <= 0 || secondStorona <= 0 || thirdStorona <= 0)
            {
                throw new Exception("Cтороны треугольника должны быть положительными");
            }
            if (firstStorona + secondStorona > thirdStorona && firstStorona + thirdStorona > secondStorona && secondStorona + thirdStorona > firstStorona)
            {
                Sides = new double[] { firstStorona, secondStorona, thirdStorona };
            }
            else
            {
                throw new Exception("Треугольника с такими сторонами не сущетсвует");
            }
        }
        public double this[int index]
        {
            get { return Sides[index]; }
            set
            {
                if (value <= 0)
                {
                    throw new Exception("Cтороны треугольника должны быть положительными");
                }
                if (Sides[1] + Sides[2] <= value || Sides[1] + value <= Sides[2] || Sides[2] + value <= Sides[1])
                {
                    throw new Exception("Треугольника с такими сторонами не сущетсвует");
                }
                if (index < 0 || index > 2)
                {
                    throw new Exception("Обращение может только быть к 0, 1 и 2");
                }
                Sides[index] = value;
            }
        }
        public void Perimetr()
        {
            double perimetr = Sides[0] + Sides[1] + Sides[2];
            Console.WriteLine("Периметр треугольника: " + perimetr);
        }
        public double Square()
        {
            double polyPerimetr = (Sides[0] + Sides[1] + Sides[2]) / 2;
            return Math.Sqrt(polyPerimetr * (polyPerimetr - Sides[0]) * (polyPerimetr - Sides[1]) * (polyPerimetr - Sides[2]));
        }
        public string ToString()
        {
            return $"Cтороны треугольника: {Sides[0]}, {Sides[1]}, {Sides[2]}";
        }
        public static Triangle operator ++(Triangle triangle)
        {
            triangle[0]++;
            triangle[1]++;
            triangle[2]++;
            return triangle;
        }
        public static Triangle operator --(Triangle triangle)
        {
            triangle[0]--;
            triangle[1]--;
            triangle[2]--;
            if (triangle[0] <= 0 || triangle[1] <= 0 || triangle[2] <= 0)
            {
                throw new Exception("Cтороны треугольника должны быть положительными");
            }
            return triangle;
        }
        public static Triangle operator +(Triangle triangle1, Triangle triangle2)
        {
            double side1 = triangle1[0] + triangle2[0];
            double side2 = triangle1[1] + triangle2[1];
            double side3 = triangle1[2] + triangle2[2];
            if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
            {
                throw new Exception("Нового треугольника с такими сторонами не сущетсвует");
            }
            return new Triangle(side1, side2, side3);
        }
        public static Triangle operator -(Triangle triangle1, Triangle triangle2)
        {
            double side1 = triangle1[0] - triangle2[0];
            double side2 = triangle1[1] - triangle2[1];
            double side3 = triangle1[2] - triangle2[2];
            if (side1 <= 0 || side2 <= 0 || side3 <= 0)
            {
                throw new Exception("У нового треугольника отрицательная сторона");
            }
            if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
            {
                throw new Exception("Нового треугольника с такими сторонами не сущетсвует");
            }
            return new Triangle(side1, side2, side3);
        }
        public static Triangle operator *(Triangle triangle1, Triangle triangle2)
        {
            double side1 = triangle1[0] * triangle2[0];
            double side2 = triangle1[1] * triangle2[1];
            double side3 = triangle1[2] * triangle2[2];
            if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
            {
                throw new Exception("Нового треугольника с такими сторонами не сущетсвует");
            }
            return new Triangle(side1, side2, side3);
        }
        public static Triangle operator /(Triangle triangle1, Triangle triangle2)
        {
            double side1 = triangle1[0] / triangle2[0];
            double side2 = triangle1[1] / triangle2[1];
            double side3 = triangle1[2] / triangle2[2];
            if (side1 <= 0 || side2 <= 0 || side3 <= 0)
            {
                throw new Exception("У нового треугольника отрицательная сторона");
            }
            if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
            {
                throw new Exception("Нового треугольника с такими сторонами не сущетсвует");
            }
            return new Triangle(side1, side2, side3);
        }
        public static bool operator ==(Triangle triangle1, Triangle triangle2)
        {
            return triangle1.Square() == triangle2.Square();
        }
        public static bool operator !=(Triangle triangle1, Triangle triangle2)
        {
            return triangle1.Square() != triangle2.Square();
        }
        public static bool operator >(Triangle triangle1, Triangle triangle2)
        {
            return triangle1.Square() > triangle2.Square();
        }
        public static bool operator <(Triangle triangle1, Triangle triangle2)
        {
            return triangle1.Square() < triangle2.Square();
        }
        public static bool operator >=(Triangle triangle1, Triangle triangle2)
        {
            return triangle1.Square() >= triangle2.Square();
        }
        public static bool operator <=(Triangle triangle1, Triangle triangle2)
        {
            return triangle1.Square() <= triangle2.Square();
        }
        public static implicit operator Triangle(double sideLength)
        {
            return new Triangle(sideLength, sideLength, sideLength);
        }
        public static explicit operator double(Triangle triangle)
        {
            return triangle.Sides[0];
        }
    }
}