package main

import (
	"errors"
	"encoding/json"
)

type Saver interface {
	Save(data []byte) error
}

func SavePerson(person *Person, saver Saver) error {
	err := person.validate()
	if err != nil {
		return err
	}

	bytes, err := person.encode()
	if err != nil {
		return err
	}

	return saver.Save(bytes)
}

type Person struct {
	Name	string
	Phone	string
}

func (p *Person) validate() error {
	if p.Name == "" {
		return errors.New("name missing")
	}
	if p.Phone == "" {
		return errors.New("phone missing")
	}
	return nil
}

func (p *Person) encode()([]byte, error) {
	return json.Marshal(p)
}
