var fs = require("fs");
var readline = require('readline');

//var names = fs.createReadStream("names.txt");
var reader = readline.createInterface({
  input: process.stdin
});

var people = [];

reader.on("line",function(line){
  var p = line.split(":");
  var person = {first:p[0], last:p[1], age:p[2]};
  people.push(person);
});

reader.on("close",function(e){
  console.log(people);
  console.log("done");
});

