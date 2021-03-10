package main

func LoadPerson(ID int, decodePerson func(data []byte) *Person)(*Person, error) {
	if ID <= 0 {
		return nil, fmt.Errorf("invalid ID '%d' supplied", ID)
	}

	bytes, err := loadPerson(ID)
	if err != nil {
		return nil, err
	}

	return decodePerson(bytes), nil
}
