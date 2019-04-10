open MomentRe;

[@genType]
type user = {
  id: int,
  name: string,
  birthday: Js.Date.t,
  momentDate: Moment.t,
};

[@genType]
let getUser = (): user => {
  {
    id: 1,
    name: "Test",
    birthday: Js.Date.make(),
    momentDate: moment("2019-01-01"),
  };
};

[@genType]
let getUserAsync = (): Js.Promise.t(user) => {
  Js.Promise.resolve({
    id: 2,
    name: "Test2",
    birthday: Js.Date.make(),
    momentDate: moment("1999-04-12"),
  });
};
