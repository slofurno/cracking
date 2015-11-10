var words = ["qwerty","wertyq","ytrewq","asdf","fdsa","sdfa","dfg","fgd"];
words.sort();

console.log(words);

ana = words.slice();

ana.sort((a,b)=>{
  var c1 = [].slice.call(a).map(x=>x.charCodeAt(0)).reduce((a,c)=>a+c);
  var c2 = [].slice.call(b).map(x=>x.charCodeAt(0)).reduce((a,c)=>a+c);
  return c1-c2;
});

console.log(ana);
