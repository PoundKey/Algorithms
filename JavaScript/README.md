#Classic JavaScript Pitfalls
Certainly I feel that I have been spoiled by JavaScipt these days; I mean, it's just... ubiquitous. I kinda miss the old days when I thought that it's a sucky language and would not never have to touch the deep inside of it. However to my understanding the current trend is:
- frontend --- JavaScript (AngularJS, BackboneJS, EmberJS...)
- backend --- JavaScript (NodeJS)
- Hybrid Mobile Appication --- JavaScript (Cordova, Ionic, PhoneGap...)
- Testing Automation --- JavaScript (PhantomJS, Selenium, CapserJS...)
- Cross Platform Desktop Application: Oh yeah, finally, let us show off some C#.NET, Cocoa Desktop, QT skills, but the answer is... maybe JavaScript...? (Node Webkit)

Gosh Darn it! Give me a break.

I miss you all, buddies; and I truly like your syntax candies: Ruby, Python, even those C-family members... But sorry, not you, my dear PHP.

It's a good time to cite down some common and classic pitfalls what I encountered over my JavaScript journey.

### #1: All about the scope
```javascript
  var arr = 10;
  it();

  function it() {
    var arr = 21;
    alt();
    console.log(arr);
  }

  function alt() {
    arr = arr*5;
    console.log(arr);
  }

  // output: 50, 21
```

### #2: Hoist the local variable in function and block scope.
```javascript
  var a = 1;
  function it() {
    console.log(a)
    var a = 2;
    console.log(a)
  }
  it();

  // output: undefined, 2

```

### #3 Object-Oriented JavaScript

// function declaration
```javascript
  function Person(name, age, job){
      this.name = name;
      this.age = age;
      this.job = job;
      this.detail = function(){
          console.log("Name: " + this.name);
          console.log("Age: " + this.age);
          console.log("Job: " + this.job);
          console.log(this);// Person { name=" ", age=.., etc...}
      }
  }
  var person = new Person("C.T Xue", 22, 'Software Developer');
  person.detail();

```

### #4 Anonymous closure functional block
```javascript
(function () {
    // ... all vars and functions are in this scope only
    // still maintains access to all globals
}());

//module with global variables $ and YAHOO as parameters
(function ($, YAHOO) {
// now have access to globals jQuery (as $) and YAHOO in this code
}(jQuery, YAHOO));

// Singleton:

  var dataStore = (function() {
    var data = [];
    return {
      push: function (item) {
        data.push(item);
      },
      pop: function() {
        return data.pop();
      },
      length: function() {
        return data.length;
      }
    };
  }());

// Template:
var MODULE = (function () {
    var mod = {},
    privateVariable = 1;
    function privateMethod() {
        // ...
    }

    mod.moduleProperty = 1;
    mod.moduleMethod = function () {
        // ...
    };

    return mod;
}());

// Extend a module:
var MODULE = (function (mod) {
    mod.anotherMethod = function () {
        // added method...
    };

    return mod;
}(MODULE));

// Class-like Way:
function newDataStore() {
    var data = [];
    return {
        push: function (item) {
            data.push(item);
        },
        pop: function() {
            return data.pop();
        },
        length: function() {
            return data.length;
        }
    };
}
var dataStore = newDataStore();
```

### #5 Anonymous closure functional block
```javascript
// Class Prototyping as of ECMAScript 5.1

function Templater() {
    this._templates = {};
}

Templater.prototype = {
    _supplant: function(str, params) {
        for (var prop in params) {
            str.split("{" + prop +"}").join(params[prop]);
        }
        return str;
    },
    render: function(name, params) {
        if (typeof this._templates[name] !== "string") {
            throw "Template " + name + " not found!";
        }

        return this._supplant(this._templates[name], params);
    },
    defineTemplate: function(name, template) {
        this._templates[name] = template;
    }
};

var templater = new Templater();

// A more concrete example:

function Datastore(name) {
  this.data = [];
  this.name = name;
}

Datastore.prototype = {
  yield : function () {
    console.log('Datastore name: ' + this.name);
  },
  length : function () {
    console.log('Datastore.length: ' + this.data.length);
  },
  add : function (item) {
    this.data.push(item);
  }
}

var db = new Datastore('Redis');

// A combined example of Clousre, Singleton and Class Prototype.

var DB = (function(){

  var basic = 21;

  function Datastore(name) {
    this.data = [];
    this.name = name;
  };

  Datastore.prototype = {
    yield : function () {
      console.log('Datastore name: ' + this.name);
    },
    length : function () {
      console.log('Datastore.length: ' + this.data.length);
    },
    add : function (item) {
      this.data.push(item);
    },
    show: function () {
      console.log('Static Basic: ' + basic);
      basic  = basic += 21;
    }
  };

  return Datastore;

}());

// In such case, staitc variables name collision can be avoided (eg: var basic)
// And the static variable basic is shared and always kept in the Memory
var db = new DB('Redis');

```

### #6 jQuery simplified with closure
```javascript
(function() {
    var privateVariable1;
    var privateVariable2;
    var jQuery = {
      /* all public methods go here */
     };
    window.jQuery = jQuery.
})();

```

###7 Call and Apply
```javascript
// one sentence description: they're capable of changing the context (this)
func.call(this, arg1, arg2, arg3) == func.apply(this, arguments) == this.func(arg1, arg2, arg3)

// a more concrete example
var obj1 = { which : "obj1" },
    obj2 = { which : "obj2" };

function execute(arg1, arg2){
  console.log(this.which, arg1, arg2);
}

execute("UBC", "Vancouver");
//output: undefined 'UBC' 'Vancouver' :the context is window object

execute.call(obj1, "UBC", "Vancouver");
//using call, output: obj1 UBC Vancouver :now the context is obj1

execute.apply(obj2, ["UBC", "Vancouver"]);
//using apply, output: obj2 UBC Vancouver :now the context is obj2

// another example
var friend = {
    car: false,
    lendCar: function ( canLend ){
      this.car = canLend;
 }

};

var me = {
    car: false,
    gotCar: function(){
      return this.car === true;
  }
};

console.log(me.gotCar()); // false

friend.lendCar.call(me, true);

console.log(me.gotCar()); // true

friend.lendCar.apply(me, [false]);

console.log(me.gotCar()); // false

// the power is all about borrowing a function from another object;
// in the example above, 'me' borrows the function lendCar from the 'friend'

```









