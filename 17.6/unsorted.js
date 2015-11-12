var arr = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19];

arr = [8,7,6,5,4,3,2,1,0];

var i = arr.length-2;


var min = arr[arr.length-1];
var max = arr[0];
var mini = arr.length-1;
var maxi = 0;

var tevs = [];

while(i>=0){
  if(arr[i]<min){
    min = arr[i];
  }else{
    mini = i;
    //tevs.push(i);
  }
  i--;
}

i=1;

while(i<=arr.length-1){
  if(arr[i]>max){
    max = arr[i];
  }else{
    maxi=i;
    //tevs.push(i);
  }
  i++;
}

tevs.sort();
console.log(mini,maxi);
