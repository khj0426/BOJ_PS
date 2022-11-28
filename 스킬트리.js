// 프로그래머스 스킬트리
// 자바스크립트 map->var m = new Map(), 값 넣기 m.set(key,value)
// 값 가져오기 m.get(key),값이 없을떄 undefined

function solution(skill, skill_trees) {
  let answer = 0;
  const m = new Map();
  for (var i = 0; i < skill.length; i++) {
    m.set(skill[i], i);
  }

  for (var i = 0; i < skill_trees.length; i++) {
    let not_valid = false;
    let index = 0;
    for (let j = 0; j < skill_trees[i].length; j++) {
      const find = m.get(skill_trees[i][j]);
      if (find != undefined) {
        if (index != find) {
          not_valid = true;
          break;
        } else {
          index++;
        }
      }
    }
    if (not_valid == false) {
      answer++;
    }
  }

  return answer;
}
