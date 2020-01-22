using System;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Net;

namespace Helper
{
    public static class PasswordGenerator
    {
        //init array of words to be potentally used in the password
        public static string[] words = getWords();

        public static string Generate(string keyWord)
        {
            //init final string
            string final = null;

            int wordListLength = words.Length;

            Random ran = new Random();
            //number of words in the password
            int numberOfWords = ran.Next(3, 5);
            //the slot in the string array that will be deformed 
            int deformSlot = ran.Next(numberOfWords);
            //the slot in the string array that will have its first letter capitaized
            int capitalizeSlot = ran.Next(numberOfWords);

            //init the array of words that will be in the password
            string[] wordsOfPass = new string[numberOfWords];
            //the slot in the array of password words that will contain the keyword passed in by the user
            int keyWordSlot = ran.Next(numberOfWords);

            //loop to set all the words in the array for the password
            for(int i = 0; i < wordsOfPass.Length; i++)
            {
                if(i == keyWordSlot)
                {
                    if(keyWordSlot == deformSlot)
                    {
                        wordsOfPass[i] = Deform(keyWord);
                    }
                    else if(keyWordSlot == capitalizeSlot)
                    {
                        string caped = Capitalize(keyWord);
                        wordsOfPass[i] = caped;
                    }
                    else
                    {
                        wordsOfPass[i] = keyWord;
                    }
                }
                else
                {
                    string word = words[ran.Next(wordListLength)];
                    
                    if(i == deformSlot)
                    {
                        wordsOfPass[i] = Deform(word);
                    }
                    else if(i == capitalizeSlot)
                    {
                        string caped = Capitalize(word);
                        wordsOfPass[i] = caped;
                    }
                    else
                    {
                        wordsOfPass[i] = word;
                    }
                }
            }

            //loop to construct the array of strings into the final string which is the password that will be given to the user
            foreach(string word in wordsOfPass)
            {
                final += word;
            }

            return final;
        }

        //method for capitalizing words
        public static string Capitalize(string input)
        {
            char[] wordArray = input.ToCharArray();
            wordArray[0] = Char.ToUpper(wordArray[0]);

            return new string(wordArray);
        }
        //method for deforming words in the password
        public static string Deform(string input)
        {
            string wordFinal = null;

            bool deformed = false;

            foreach(char letter in input)
            {
                char letterFinal = letter;

                //to ensure that only one word is deformed 
                if(deformed == false)
                {
                    //to ensure that upper case letters are not deformed
                    if(Char.IsUpper(letter) == true)
                    {
                        wordFinal += letterFinal;
                    }
                    else
                    {
                        //list of rules for deforming

                        if(letter == 's')
                        {
                            wordFinal += '$';
                            deformed = true;
                        }
                        else if(letter == 'o')
                        {
                            wordFinal += '0';
                            deformed = true;
                        }
                        else if(letter == 'h')
                        {
                            wordFinal += '#';
                            deformed = true;
                        }
                        else if(letter == 'l')
                        {
                            wordFinal += '|';
                            deformed = true;
                        }
                        else if(letter == 'p')
                        {
                            wordFinal += '?';
                            deformed = true;
                        }
                        else if(letter == 'c')
                        {
                            wordFinal += '(';
                            deformed = true;
                        }
                        else if(letter == 'x')
                        {
                            wordFinal += '+';
                            deformed = true;
                        }
                        else if(letter == 'f')
                        {
                            wordFinal += '*';
                            deformed = true;
                        }
                        else if(letter == 'i')
                        {
                            wordFinal += '!';
                            deformed = true;
                        }
                        else if(letter == 'v')
                        {
                            wordFinal += '^';
                            deformed = true;
                        }
                        else if(letter == 'm')
                        {
                            wordFinal += '"';
                            deformed = true;
                        }
                        else if(letter == 'k')
                        {
                            wordFinal += '=';
                            deformed = true;
                        }


                        //for if the word has not yet been deformed but the letter does not match any of the rules 
                        else
                        {
                            wordFinal += letter;
                        }
                    }
                }
                else
                {
                    wordFinal += letter;
                }
            }

            return wordFinal;
        }
        
        //download a list of words to be used
        public static string[] getWords()
        {
            string[] words = null;

            string filePath = @"words.txt";
            try
            {
                words = File.ReadAllLines(filePath);
            }
            catch(Exception exe)
            {
                Console.WriteLine(exe.ToString());
                Console.WriteLine("<!------------ ERROR: A file of words could not be found, plese place one in the program directory. ------------!>");
                File.Create(@"words.txt");
                Console.ReadLine();
            }
            
            return words;
        }
    }
}
