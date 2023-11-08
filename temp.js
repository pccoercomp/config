/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  const romanSymbols = [
    { symbol: "I", value: 1 },
    { symbol: "V", value: 5 },
    { symbol: "X", value: 10 },
    { symbol: "L", value: 50 },
    { symbol: "C", value: 100 },
    { symbol: "D", value: 500 },
    { symbol: "M", value: 1000 },
  ];

  let res = 0;
  for (let i = s.length - 1; i > 0; i--) {
    let found = romanSymbols.find((item) => item.symbol == s[i]);
    if (
      found.value < romanSymbols.find((item) => item.symbol == s[i - 1]).value
    )
      res += found.value;
    else {
      res +=
        found.value -
        romanSymbols.find((item) => item.symbol == s[i - 1]).value;
      i--;
    }

    console.log(s[i], found, res);
  }
  return res;
};
