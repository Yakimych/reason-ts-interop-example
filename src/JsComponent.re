[@bs.deriving abstract]
type jsComponentTexts = {
  numberLabel: string,
  boolLabel: string,
};

[@bs.deriving abstract]
type jsProps = {
  someNumber: int,
  someBool: bool,
  texts: jsComponentTexts,
};

[@bs.module "./JsComponent"]
external myJSReactClass: ReasonReact.reactClass = "default";

let make = (~someNumber, ~someBool, ~texts, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~someNumber, ~someBool, ~texts),
    children,
  );
