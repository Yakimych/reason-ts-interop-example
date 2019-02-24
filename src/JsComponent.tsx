import * as React from "react";

export type Props = {
  someNumber: number;
  someBool: boolean;
  // texts: JsComponentTexts;
};

// export type JsComponentTexts = {
//   NumberLabel: string;
//   BoolLabel: string;
// };

const JsComponent: React.FunctionComponent<Props> = props => (
  <>
    {/* <label>{props.texts.NumberLabel}</label> */}
    <span>{props.someNumber}</span>
    {/* <label>{props.texts.BoolLabel}</label> */}
    <span>{props.someBool.toString()}</span>
  </>
);

export default JsComponent;
