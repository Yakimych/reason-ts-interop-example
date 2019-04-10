[@genType]
type user = {
  id: int,
  name: string,
  birthday: Js.Date.t,
};

[@genType]
let getUser = (): user => {
  {id: 1, name: "Test", birthday: Js.Date.make()};
};

[@genType]
let getUserAsync = (): Js.Promise.t(user) => {
  Js.Promise.resolve({id: 2, name: "Test2", birthday: Js.Date.make()});
};
