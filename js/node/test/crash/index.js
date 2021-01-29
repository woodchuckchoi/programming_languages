import { Person } from './modules/person.js';
import { Logger } from './modules/logger.js';

const logger = new Logger();

logger.on('message', (data)=> {
    console.log(`Called Listener: `, data);
})

logger.log('Hello World!');

// const person1 = new Person('John Doe', 30);
// person1.greeting();
