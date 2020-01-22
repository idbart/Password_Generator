using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Helper;

namespace PasswordGenerator
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                passwordGet();
            }
        }

        static void passwordGet()
        {
            //ask the user for a keyword
            Console.WriteLine("Input Key Word To Genarate Password:");

            string keyWord = Console.ReadLine();

            //generate password 
            string passwordFinal = Helper.PasswordGenerator.Generate(keyWord);

            //print the password to the user
            Console.WriteLine("Your Password is:" + passwordFinal);
            Console.ReadLine();

            Console.Clear();
        }
    }
}
