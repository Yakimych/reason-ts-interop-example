import React from "react";
import ReactDOM from "react-dom";
import "./index.css";
import App from "./App.bs";
import * as serviceWorker from "./serviceWorker";

type Texts = {
  ok: string;
  cancel: string;
};

const texts: Texts = {
  ok: "Ok",
  cancel: "Cancel"
};

ReactDOM.render(
  <App someText="Some Text" texts={texts} />,
  document.getElementById("root")
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();
