var arr = [].slice.call('a'.repeat(50)).map(x=>Math.random()*200|0);
var n = arr[5];
var offset = Math.random()*50|0;
arr.sort((a,b)=>a-b);

var rotated = arr.concat(arr).slice(offset,offset+50);

var jumpsearch = function(arr,n){
  return (function(){

    var _jumpsearch = function(arr, start, end, n){

      if (end-start<2){
        return start;
      }

      var mid = ((end-start)/2 + start)|0;
      console.log("mid:",mid);

      if ((arr[start]<=arr[mid-1] && n<=arr[mid-1] && n>=arr[start]) ||
      (arr[mid]<=arr[end-1] && (n>arr[end-1] || n<arr[mid]))){
        return _jumpsearch(arr,start,mid,n);
      }else{
        return _jumpsearch(arr,mid,end,n);
      }

    };

    return _jumpsearch(arr,0,arr.length,n);
  }(arr,n));
};

console.log("Were looking for:",n);
var i = jumpsearch(arr,n);
console.log("is this your number?",arr[i], "at index:", i);

