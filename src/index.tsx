import React from "react";
import ReactDOM from "react-dom";
import "./index.css";
import App from "./App.bs";
import * as serviceWorker from "./serviceWorker";
import { JsComponentTexts } from "./JsComponent";

type Texts = {
  Ok: string;
  Cancel: string;
};

const texts: Texts = {
  Ok: "Ok",
  Cancel: "Cancel"
};

const jsComponentTexts: JsComponentTexts = {
  NumberLabel: "The number value is:",
  BoolLabel: "The bool value is:"
};

ReactDOM.render(
  <App
    someText="Some Text"
    texts={texts}
    jsComponentTexts={jsComponentTexts}
  />,
  document.getElementById("root")
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();
