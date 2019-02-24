[@bs.deriving abstract]
type jsProps = {
  someNumber: int,
  someBool: bool,
};

[@bs.module "./JsComponent"]
external myJSReactClass: ReasonReact.reactClass = "default";

let make = (~someNumber, ~someBool, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~someNumber, ~someBool),
    children,
  );
