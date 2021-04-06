function formatName(user) {
  return user.firstName + ' ' + user.lastName;
}

const user = {
  firstName: 'Harper',
  lastName: 'Perez',
};

function getGreeting(user) {
  if (user) {
    return <h1>Hello, {formatName(user)}!</h1>;  }
  return <h1>Hello, Stranger.</h1>;}

ReactDOM.render(getGreeting(user), document.getElementById('root'));

const title = response.potentiallyMaliciousInput;
// This is safe:
const element = <h1>{title}</h1>;

/*

React DOM escapes any values embedded in JSX before rendering them. Thus it ensures that you can never inject anything that’s not explicitly written in your application. 

*/

// product of react createElement
const element = {
  type: 'h1',
  props: {
    className: 'greeting',
    children: 'Hello, world!'
  }
};

/*
React elements are immutable. Once you create an element, you can’t change its children or attributes.

React DOM compares the element and its children to the previous one, and only applies the DOM updates necessary to bring the DOM to the desired state.

*/

// Functional components
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}

Class Components
class Welcome extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}

calling Elements
<Welcome name:"khabib" />
props = { name: "khabib" }
 
/*
Try to eliminate as much code into reusable components as possible
Props are read only, don't try to change their values, we have state for values that change
*/

/*
we need state so, that we don't have to create functions like set interval to re-render the page again and agian
we want the app to do that on its own with change in values of components
*/

/*
    Create an ES6 class, with the same name, that extends React.Component.
    Add a single empty method to it called render().
    Move the body of the function into the render() method.
    Replace props with this.props in the render() body.
    Delete the remaining empty function declaration
    
    In applications with many components, it’s very important to free up resources taken by the components when they are destroyed
    We can declare special methods on the component class to run some code when a component mounts and unmounts:
*/

class Clock extends React.Component {
  constructor(props) {
    super(props);
    this.state = {date: new Date()};
  }

  componentDidMount() {
    this.timerID = setInterval(
      () => this.tick(),
      1000
    );
  }

  componentWillUnmount() {
    clearInterval(this.timerID);
  }

  tick() {    this.setState({      date: new Date()    });  }
  render() {
    return (
      <div>
        <h1>Hello, world!</h1>
        <h2>It is {this.state.date.toLocaleTimeString()}.</h2>
      </div>
    );
  }
}

ReactDOM.render(
  <Clock />,
  document.getElementById('root')
);
---------------------------------------------------------
// this will not re-render a component:

// Wrong
this.state.comment = 'Hello';

// Instead, use setState():

// Correct
this.setState({comment: 'Hello'});

--------------------------------------------------------------
// Because this.props and this.state may be updated asynchronously, you should not rely on their values for calculating the next state.
// this code may fail to update the counter:

// Wrong
this.setState({
  counter: this.state.counter + this.props.increment,
});
 /*
To fix it, use a second form of setState() that accepts a function rather than an object. That function will receive the previous state as the first argument, and the props at the time the update is applied as the second argument:
*/

// Correct
this.setState((state, props) => ({
  counter: state.counter + props.increment
}));
-----------------------------------------------------------------
class Toggle extends React.Component {
  constructor(props) {
    super(props);
    this.state = {isToggleOn: true};

    // This binding is necessary to make `this` work in the callback    
    // binding in constructor itself is always considered a better practice
    this.handleClick = this.handleClick.bind(this);  }

  handleClick() {    this.setState(state => ({      isToggleOn: !state.isToggleOn    }));  }
  render() {
    return (
      <button onClick={this.handleClick}>        
      	{this.state.isToggleOn ? 'ON' : 'OFF'}
      </button>
    );
  }
}

ReactDOM.render(
  <Toggle />,
  document.getElementById('root')
);
