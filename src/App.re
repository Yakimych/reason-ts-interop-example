[%bs.raw {|require('./App.css')|}];

type state = {
  isLoading: bool,
  content: string,
};

type action =
  | LoadingStart
  | Loaded(string);

let component = ReasonReact.reducerComponent("App");

let make = (~someText, _children) => {
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
type jsProps = {someText: string};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~someText=jsProps->someTextGet, [||])
  );
