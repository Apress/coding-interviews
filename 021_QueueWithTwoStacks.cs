// Coding Interviews: Questions, Analysis & Solutions
// Harry He

using System;
using System.Collections.Generic;

namespace QueueWithStacks
{
    public class QueueWithTwoStacks<T>
    {
        public void Enqueue(T item)
        {
            stack1.Push(item);
        }

        public T Dequeue()
        {
            if (stack2.Count == 0)
            {
                while (stack1.Count > 0)
                {
                    T item = stack1.Peek();
                    stack1.Pop();
                    stack2.Push(item);
                }
            }

            if (stack2.Count == 0)
                throw new InvalidOperationException("Queue is Empty");

            T head = stack2.Peek();
            stack2.Pop();

            return head;
        }

        private Stack<T> stack1 = new Stack<T>();
        private Stack<T> stack2 = new Stack<T>();
    }

    class Program
    {
        static void Test(char actual, char expected)
        {
            if (actual == expected)
                Console.WriteLine("Test passed.");
            else
                Console.WriteLine("Test failed.");
        }

        static void Main(string[] args)
        {
            QueueWithTwoStacks<char> queue = new QueueWithTwoStacks<char>();

            queue.Enqueue('a');
            queue.Enqueue('b');
            queue.Enqueue('c');

            char head = queue.Dequeue();
            Test(head, 'a');

            head = queue.Dequeue();
            Test(head, 'b');

            queue.Enqueue('d');
            head = queue.Dequeue();
            Test(head, 'c');

            queue.Enqueue('e');
            head = queue.Dequeue();
            Test(head, 'd');

            head = queue.Dequeue();
            Test(head, 'e');
            
            try
            {
                head = queue.Dequeue();
                Console.WriteLine("Test failed.");
            }
            catch(InvalidOperationException)
            {
                Console.WriteLine("Test passed.");
            }
        }
    }
}
