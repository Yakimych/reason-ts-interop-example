import * as React from "react";

type Props = {
  someProp: string;
};

const JsComponent: React.FunctionComponent<Props> = props => (
  <>
    <span>{props.someProp}</span>
  </>
);

export default JsComponent;
