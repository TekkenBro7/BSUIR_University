using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interfaces;
using CustomException;
using OrderRealization;

namespace Collections
{
    
    internal class MyCustomCollection<T> : ICustomCollection<T>, IEnumerable<T>
    {
        private class Node
        {
            public T Value { get; set; }
            public Node? Next { get; set; }
            public Node(T value)
            {
                Value = value;
                Next = null;
            }
        }
        private Node? Head;
        private Node? CurrentNode;
        private int Amount;
        public MyCustomCollection()
        {
            Head = null;
            CurrentNode = null;
            Amount = 0;
        }
        public T this[int index]
        {
            get
            {
                if (index < 0 || index >= Amount)
                {
                    throw new IndexOutOfRangeException("Index is out of range");
                }
                Node? currentNode = Head;
                for (int i = 0; i < index; i++)
                {
                    currentNode = currentNode.Next;
                }
                return currentNode.Value;
            }
            set
            {
                if (index < 0 || index >= Amount)
                {
                    throw new IndexOutOfRangeException("Index is out of range");
                }
                Node currentNode = Head;
                for (int i = 0; i < index; i++)
                {
                    currentNode = currentNode.Next;
                }
                currentNode.Value = value;
            }
        }
        public void Reset()
        {
            CurrentNode = Head;
        }
        public void Next()
        {
            if (CurrentNode != null)
            {
                CurrentNode = CurrentNode.Next;
            }
        }
        public T Current()
        {
            if (CurrentNode != null)
            {
                return CurrentNode.Value;
            }
            throw new InvalidOperationException("No elements");
        }
        public int Counnt
        {
            get
            {
                return Amount;
            }
        }
        public void Add(T item)
        {
            Node newNode = new(item);
            if (Head == null)
            {
                Head = newNode;
                CurrentNode = newNode;
            }
            else
            {
                while (CurrentNode.Next != null)
                {
                    CurrentNode = CurrentNode.Next;
                }
                CurrentNode.Next = newNode;
                CurrentNode = newNode;
            }
            Amount++;
        }
        public void Remove(T item)
        {
            if (Head == null)
            {
                return;
            }
            if (EqualityComparer<T>.Default.Equals(Head.Value, item))
            {
                Head = Head.Next;
                Amount--;
                CurrentNode = Head;
                return;
            }
            else
            {
                Node? previousNode = Head;
                Node? currentNode = Head.Next;
                while (currentNode != null)
                {
                    if (EqualityComparer<T>.Default.Equals(currentNode.Value, item))
                    {
                        previousNode.Next = currentNode.Next;
                        Amount--;
                        CurrentNode = previousNode.Next;
                        if (CurrentNode == null)
                        {
                            CurrentNode = Head;
                        }
                        return;
                    }
                    previousNode = currentNode;
                    currentNode = currentNode.Next;
                }
                throw new MyCustomException("No such element");
            }
        }
        public bool Contains(string customerName)
        {
            foreach (T item in this)
            {
                if (item is Order order && order.CustomerName == customerName)
                {
                    return true;
                }
            }
            return false;
        }
        public T RemoveCurrent()
        {
            if (CurrentNode != null)
            {
                T removedValue = CurrentNode.Value;
                if (CurrentNode == Head)
                {
                    Head = Head.Next;
                    CurrentNode = Head;
                }
                else
                {
                    Node previousNode = Head;
                    while (previousNode.Next != CurrentNode)
                    {
                        previousNode = previousNode.Next;
                    }
                    previousNode.Next = CurrentNode.Next;
                    CurrentNode = previousNode;
                }
                Amount--;
                return removedValue;
            }
            throw new InvalidOperationException("No elements");
        }
        public IEnumerator<T> GetEnumerator()
        {
            Node? currentNode = Head;
            while(currentNode != null)
            {
                yield return currentNode.Value;
                currentNode = currentNode.Next;
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}