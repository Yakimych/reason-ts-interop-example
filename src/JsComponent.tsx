import * as React from "react";
import { useEffect, useState } from "react";
import { getUser, user as User, getUserAsync } from "./Api/ApiCaller.gen";

export type Props = {
  someNumber: number;
  someBool: boolean;
  texts: JsComponentTexts;
};

export type JsComponentTexts = {
  NumberLabel: string;
  BoolLabel: string;
};

const JsComponent: React.FunctionComponent<Props> = props => {
  const [user, setUser] = useState<User>(getUser());

  useEffect(() => {
    getUserAsync().then(u => {
      setUser(u);
      console.log("user:", user);
    });
  }, []);

  return (
    <>
      <label>{props.texts.NumberLabel}</label>
      <span>{props.someNumber}</span>
      <label>{props.texts.BoolLabel}</label>
      <span>{props.someBool.toString()}</span>
      <div>
        <h2>User</h2>
        <div>{user.id}</div>
        <div>{user.name}</div>
        <div>{user.birthday.toISOString()}</div>
        <div>{user.momentDate.toISOString()}</div>
      </div>
    </>
  );
};

export default JsComponent;
