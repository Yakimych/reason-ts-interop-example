[@bs.deriving abstract]
type jsProps = {someProp: string};

[@bs.module "./JsComponent"]
external myJSReactClass: ReasonReact.reactClass = "default";

let make = (~someProp, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~someProp),
    children,
  );
