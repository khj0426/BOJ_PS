const utils = {
  issameNum: 1,
  isnotsameNum: 2,
};

const limitexceed = (number, limit, power) => {
  if (number <= limit) {
    return number;
  }
  return power;
};

const comparemeasure = (numfirst, numsecond) => {
  if (numfirst === numsecond) {
    return utils.issameNum;
  }
  return utils.isnotsameNum;
};

const getmeasure = (number) => {
  let sumofmeasure = 0;
  for (let i = 1; i * i <= number; i += 1) {
    if (number % i === 0) {
      const dividenum = number / i;
      sumofmeasure += comparemeasure(dividenum, i);
    }
  }
  return sumofmeasure;
};
function solution(number, limit, power) {
  let answer = [...new Array(number)].map((number, index) => index + 1);
  answer = answer.reduce(
    (sums, getcurrentsum) =>
      sums + limitexceed(getmeasure(getcurrentsum), limit, power)
  );

  return answer;
}
