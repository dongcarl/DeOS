/* eslint-disable import/no-extraneous-dependencies, no-unused-expressions */

import { should } from 'chai';
import { describe, it, beforeEach } from 'mocha';

import { createStore } from 'redux';
import { combineReducers } from 'redux-immutable';

import dogReducer from '../src/reducers/dog-reducer';
import { makeBark } from '../src/actions/dog-actions';

should();
let store;

describe('App State', () => {
  describe('Dog', () => {
    beforeEach(() => {
      store = createStore(combineReducers({
        dog: dogReducer,
      }));
    });
    describe('makeBark', () => {
      it('should make hasBarked go from false to true', () => {
        store.getState().getIn(['dog', 'hasBarked']).should.be.false;
        store.dispatch(makeBark());
        store.getState().getIn(['dog', 'hasBarked']).should.be.true;
      });
    });
  });
});
