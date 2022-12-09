function valid(want, discountmap, wantnumbermap) {
  let isvalid = true;
  want.forEach((eachwanted, index) => {
    if (discountmap.has(eachwanted) == false) {
      isvalid = false;
    }
    if (discountmap.get(eachwanted) < wantnumbermap.get(eachwanted)) {
      isvalid = false;
    }
  });
  return isvalid;
}

function solution(want, number, discount) {
  let answer = 0;
  let count = 0;
  const stack = [];

  const wantnumberMapping = new Map();
  want.forEach((eachwanted, index) => {
    wantnumberMapping.set(eachwanted, number[index]);
    count += number[index];
  });

  const discountmap = new Map();
  for (let i = 0; i < count; i++) {
    stack.push(discount[i]);
    if (discountmap.has(discount[i]) == false) {
      discountmap.set(discount[i], 1);
    } else {
      const discountvalue = discountmap.get(discount[i]) + 1;
      discountmap.delete(discount[i]);
      discountmap.set(discount[i], discountvalue);
    }
  }

  if (valid(want, discountmap, wantnumberMapping)) {
    answer += 1;
  }
  for (let i = count; i < discount.length; i++) {
    const firststackcount = discountmap.get(stack[0]) - 1;
    discountmap.delete(stack[0]);
    discountmap.set(stack[0], firststackcount);
    stack.shift();

    stack.push(discount[i]);
    if (discountmap.has(discount[i]) == false) {
      discountmap.set(discount[i], 1);
    } else {
      const discountvalue = discountmap.get(discount[i]) + 1;
      discountmap.delete(discount[i]);
      discountmap.set(discount[i], discountvalue);
    }

    if (valid(want, discountmap, wantnumberMapping)) {
      answer += 1;
    }
  }

  return answer;
}
