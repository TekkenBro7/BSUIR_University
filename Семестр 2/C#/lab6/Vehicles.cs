using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transports
{
    abstract class Vehicle
    {
        protected double Speed;
        protected double Weight;
        protected int CreateYear;
        public Vehicle(double speed, double weight, int createYear)
        {
            Speed = speed;
            Weight = weight;
            CreateYear = createYear;
        }
        public abstract void Move();
        public abstract void ChangeSpeed(double speed);
        public abstract double GetSpeed();
        public virtual void Massa()
        {
            Console.WriteLine("Вес составляет: " + Weight);
        }
        public virtual void Stop()
        {
            Console.WriteLine("Транспорт перестаёт двигаться");
            Speed = 0;
        }
    }
    class Car : Vehicle
    {
        private string Model;
        public Car(string model, double speed, double weight, int createYear) : base(speed, weight, createYear)
        {
            Model = model;
        }
        public string GetModel()
        {
            Console.Write("Модель машины: ");
            return Model;
        }
        public double GetWeight()
        {
            Console.Write("Масса машины: ");
            return Weight;
        }
        public override double GetSpeed()
        {
            Console.Write("Cкорость машины: ");
            return Speed;
        }
        void SetModel(string model)
        {
            Model = model;
        }
        void SetSpeed(double speed)
        {
            Speed = speed;
        }
        public override void Move()
        {
            Console.WriteLine("Машина " + Model + " едет со скоростью " + Speed + " км/ч");
        }
        public override void ChangeSpeed(double speed)
        {
            Speed = speed;
            Console.WriteLine("Машина " + Model + " изменила скорость и сейчас едет со скоростью " + speed + " км/ч");
        }
        public void Massa(double mass)
        {
            if (mass > Weight)
            {
                Weight = mass;
                Console.WriteLine("В машину загрузили вещи и масса стала равна: " + Weight);
            }
            else
            {
                Weight = mass;
                Console.WriteLine("C машины забрали вещи и масса стала равна: " + Weight);
            }
        }
    }

    sealed class AirBalloon : Vehicle
    {
        private double Capacity;
        public AirBalloon(double speed, double weight, int createYear, double capacity) : base(speed, weight, createYear)
        {
            Capacity = capacity;
        }
        public override double GetSpeed()
        {
            Console.Write("Cкорость шара: ");
            return Speed;
        }
        void SetSpeed(double speed)
        {
            Speed = speed;
        }
        public double GetCapacity()
        {
            Console.Write("Вместимость шара: ");
            return Capacity;
        }
        public override void ChangeSpeed(double speed)
        {
            Speed = speed;
            Console.WriteLine("Шар изменил скорость и сейчас летит со скоростью " + speed + " км/ч");
        }
        public override void Move()
        {
            Console.WriteLine("Шар летит со скоростью " + Speed + " км/ч");
        }
        public override void Stop()
        {
            base.Stop();
            Console.WriteLine("Шар остановился");
        }
    }
}