import React from "react";
import ReactDOM from "react-dom";
import "./index.css";
import App from "./App.bs";
import * as serviceWorker from "./serviceWorker";

type Texts = {
  Ok: string;
  Cancel: string;
};

const texts: Texts = {
  Ok: "Ok",
  Cancel: "Cancel"
};

ReactDOM.render(
  <App someText="Some Text" texts={texts} />,
  document.getElementById("root")
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();
