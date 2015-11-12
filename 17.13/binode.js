var fs = require("fs");

var names = fs.readFileSync("../first.txt", {encoding:"utf8"}).split("\n");

var biNode = function(data){
  var node1;
  var node2;

  return {node1,node2,data};
};

var strcmp = function(str1, str2){

  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();
  var len = Math.min(str1.length, str2.length);

  for(var i = 0; i<len;i++){
    var c1 = str1.charCodeAt(i);
    var c2 = str2.charCodeAt(i);

    if (c1!=c2){
      return c1-c2;
    }
  }

  return str1.length - str2.length;

};

names = names.map(x=>biNode(x));
//names.sort((a,b)=>strcmp(a.data,b.data));

var i = names.length/2|0;
var head = names[i];
names.splice(i,1);

names.forEach(x=>addNode(head,x));

var cur = convert(head);

//console.log("cur",cur);

while(cur!==undefined){
  console.log(cur.data);
  cur=cur.node2;
}

function addNode(head,node){

  if (strcmp(node.data, head.data)<0){
    if (head.node1!==undefined){
      addNode(head.node1,node);
    }else{
      head.node1 = node;
    }
  }else{
    if (head.node2!==undefined){
      addNode(head.node2,node);
    }else{
      head.node2=node;
    }
  }
}

//TODO: not doubly linked list
function convert(node){

  if (node===undefined){
    return node;
  }

  var head = convert(node.node1);
  node.node2 = convert(node.node2);

  if (head===undefined){
    return node;
  }

  var cur = head;
  while(cur.node2!==undefined){
    cur = cur.node2;
  }
  cur.node2 = node;

  return head;

}

function walkInOrder(node){

  if (node.node1!==undefined){
    walkInOrder(node.node1,node);
    //node.node1 = walkInOrder(node.node1,node);
    //node.node1.node2 = node;
  }

  console.log(node.data);

  if(node.node2!==undefined){
    walkInOrder(node.node2,node);
    //var ret = walkInOrder(node.node2,node);
    //node.node2.node1 = node;
    //return ret;
  }
  //return node;
}

function iterateInOrder(head){

  var cur = head;
  var stack = [];

  var next=function(){

    if (cur.node1!==undefined){
      while (cur.node1!==undefined){
        stack.push(cur);
        cur=cur.node1;
      }
      //return cur;
    }
  };
}
