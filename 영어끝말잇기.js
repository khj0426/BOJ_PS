function solution(n, words) {
  var answer = [];
  let number = 0;
  let string_arr = [];

  words.forEach((eachword, index) => {
    if (index >= n) {
      index = index % n;
    }
    if (index === 0) {
      number += 1;
    }

    if (string_arr.includes(eachword) && answer.length === 0) {
      answer.push(index + 1);
      answer.push(number);
      return answer;
    }
    let last_arr = string_arr[string_arr.length - 1];
    if (typeof last_arr === 'string') {
      last_arr = last_arr[last_arr.length - 1];
      if (last_arr != eachword[0] && answer.length === 0) {
        answer.push(index + 1);
        answer.push(number);
      }
    }

    string_arr.push(eachword);
  });

  // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
  if (answer.length === 0) {
    answer.push(0);
    answer.push(0);
  }
  return answer;
}
