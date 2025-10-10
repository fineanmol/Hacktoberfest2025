using System;

class AlienNameGenerator
{
    static void Main()
    {
        string[] prefixes = { "Zor", "Xan", "Qel", "Vro", "Neb", "Glu" };
        string[] middles = { "thar", "ix", "ul", "om", "ar", "eq" };
        string[] suffixes = { "on", "ax", "oid", "ar", "ium", "ex" };

        Random rnd = new Random();
        Console.WriteLine("Welcome to the Alien Name Generator!\n");

        for (int i = 0; i < 10; i++)
        {
            string alienName = prefixes[rnd.Next(prefixes.Length)]
                               + middles[rnd.Next(middles.Length)]
                               + suffixes[rnd.Next(suffixes.Length)];

            Console.WriteLine($"Alien #{i + 1}: {alienName}");
        }

        Console.WriteLine("\nPress Enter to exit...");
        Console.ReadLine();
    }
}