class Point {
  constructor(a, b) {
    this.a = a;
    this.b = b;
  }
}

function attribute(point, x, z) {
  point.a = x;
  point.b = z;
}

function main() {
  const p = new Point(10, 2);

  //   const p = { a: 10, b: 5 };

  attribute(p, 1, 2);

  console.log(`p -> a = ${p.a}`);
  console.log(`p -> b = ${p.b}`);
}

main();
