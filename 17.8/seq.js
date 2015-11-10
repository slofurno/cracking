
function random_int(min, max){
  return (Math.random()*(max-min)|0) + min;
}

var rnd = function(){
  return random_int(-10, 11);
};

var arr=[];

for(var i = 0; i<1000;i++){
  arr.push(rnd());
}



var count = 0;

for(var i = 0;i<1000;i++){

  if

}
