
function random_int(min, max){
  return (Math.random()*(max-min)|0) + min;
}

var rnd = function(){
  return random_int(-10, 11);
};

var arr=[];

for(var i = 0; i<20;i++){
  var r = rnd();
  if (r===0) continue;
  arr.push(r);
}

//arr=[2, -8, 3, -2, 4, -10];

var maxsum= 0;
var maxoffset = 0;
var maxlen = 0;

var sum = 0;
var offset = 0;
var len = 0;

for(var i = 0;i<arr.length;i++){
  if (sum+arr[i]>0){
    sum+=arr[i];
    len++;
  }else{
    sum=0;
    len=0;
    offset=i+1;
  }

  if (sum>maxsum){
    maxsum = sum;
    maxoffset=offset;
    maxlen=len;
  }
}

var range = arr.slice(maxoffset, maxoffset+maxlen);
console.log(arr);
console.log(range, maxsum);
