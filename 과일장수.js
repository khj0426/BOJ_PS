//1점부터 K점까지 점수로 분류
//M개씩 사과를 담아 포장한다.
//상자에 사과가 담기는데 가장 낮은 점수가 P인경우, 한 상자의 가격은 P*M

//k=3,m=4,[1,2,3,1,2,3,1]
//
function solution(k, m, score) {
  var answer = 0;
  score.sort((a, b) => {
    return b - a;
  });

  for (let i = 0; i < score.length; i += m) {
    if (score.length - i < m) {
      break;
    }
    let newBoxScore = [];
    for (let j = i; j < i + m; j++) {
      newBoxScore.push(score[j]);
    }
    const newScore = Math.min(...newBoxScore) * m;

    answer += newScore;
  }
  return answer;
}
