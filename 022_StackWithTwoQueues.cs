// Coding Interviews: Questions, Analysis & Solutions
// Harry He

using System;
using System.Collections.Generic;

namespace StackWithQueues
{
    public class StackWithTwoQueues<T>
    {
        public void Push(T item)
        {
            if (queue2.Count != 0)
                queue2.Enqueue(item);
            else
                queue1.Enqueue(item);
        }

        public T Pop()
        {
            if (queue1.Count == 0 && queue2.Count == 0)
                throw new InvalidOperationException("Stack is Empty");

            Queue<T> emptyQueue = queue1;
            Queue<T> nonemptyQueue = queue2;
            if (queue1.Count > 0)
            {
                emptyQueue = queue2;
                nonemptyQueue = queue1;
            }

            while (nonemptyQueue.Count > 1)
                emptyQueue.Enqueue(nonemptyQueue.Dequeue());

            return nonemptyQueue.Dequeue();
        }

        private Queue<T> queue1 = new Queue<T>();
        private Queue<T> queue2 = new Queue<T>();
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
            StackWithTwoQueues<char> stack = new StackWithTwoQueues<char>();
            stack.Push('a');
            stack.Push('b');
            stack.Push('c');

            char top = stack.Pop();
            Test(top, 'c');

            top = stack.Pop();
            Test(top, 'b');

            stack.Push('d');
            top = stack.Pop();
            Test(top, 'd');

            top = stack.Pop();
            Test(top, 'a');

            try
            {
                top = stack.Pop();
                Console.WriteLine("Test failed.");
            }
            catch (InvalidOperationException)
            {
                Console.WriteLine("Test passed.");
            }

            stack.Push('e');
            stack.Push('f');

            top = stack.Pop();
            Test(top, 'f');

            top = stack.Pop();
            Test(top, 'e');
        }
    }
}
