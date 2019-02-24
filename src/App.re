open JsComponent;

[%bs.raw {|require('./App.css')|}];

type state = {
  isLoading: bool,
  content: string,
};

type reasonTexts = {
  ok: string,
  cancel: string,
};

type action =
  | LoadingStart
  | Loaded(string);

let component = ReasonReact.reducerComponent("App");

let make = (~someText, ~texts, ~jsComponentTexts, _children) => {
  ...component,

  initialState: () => {isLoading: false, content: ""},
  reducer: (action, state) =>
    switch (action) {
    | LoadingStart => ReasonReact.Update({...state, isLoading: true})
    | Loaded(content) => ReasonReact.Update({...state, content})
    },

  render: _self => {
    <div className="App">
      <header className="App-header">
        <div> {ReasonReact.string(someText)} </div>
        <button> {ReasonReact.string(texts.ok)} </button>
        <button> {ReasonReact.string(texts.cancel)} </button>
        <JsComponent someNumber=12 someBool=false texts=jsComponentTexts />
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer">
          {ReasonReact.string("Learn React")}
        </a>
      </header>
    </div>;
  },
};

[@bs.deriving abstract]
type texts = {
  [@bs.as "Ok"]
  ok: string,
  [@bs.as "Cancel"]
  cancel: string,
};

[@bs.deriving abstract]
type jsProps = {
  someText: string,
  texts,
  jsComponentTexts,
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    jsProps => {
      let jsTexts = jsProps->textsGet;
      make(
        ~someText=jsProps->someTextGet,
        ~texts={ok: jsTexts->okGet, cancel: jsTexts->cancelGet},
        ~jsComponentTexts=jsProps->jsComponentTextsGet,
        [||],
      );
    },
  );
