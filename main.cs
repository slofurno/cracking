using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.IO;

class Program
{
  static void Main(string[] args)
  {
    var k = 30;
    var names = File.ReadLines("first.txt");
    var list = new LinkedList<string>();

    foreach(var name in names){
      list.AddLast(name);
    }

    var e1 = list.GetEnumerator();
    var e2 = list.GetEnumerator();

    var i = 0;
    while(e1.MoveNext()!=false){
      i++;
      if (i>=k){
        e2.MoveNext();
      }
    }
    Console.WriteLine(e2.Current);
  }
}
