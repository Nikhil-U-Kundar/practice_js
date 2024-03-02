import React from "react";
import ReactDOM from "react-dom";
// this is the page for:
// created by nikhil
// copyrigt 2024 87
const name = "NIKHIL";
const currentDate = new Date();
const year = currentDate.getFullYear();
ReactDOM.render(
  <div>
    <p>created by {name}</p>
    <p>copyright {year}</p>
  </div>,
  document.getElementById("root")
);
